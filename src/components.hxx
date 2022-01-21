#pragma once
#include <vector>
#include "_main.hxx"
#include "vertices.hxx"
#include "dfs.hxx"

using std::vector;



// COMPONENTS
// ----------
// Finds Strongly Connected Components (SCC) using Kosaraju's algorithm.

template <class G, class H>
auto components(const G& x, const H& xt) {
  using K = typename G::key_type;
  vector2d<K> a; vector<K> vs;
  // original dfs
  auto vis = createContainer(x, bool());
  for (auto u : x.vertexKeys())
    if (!vis[u]) dfsEndLoop(vs, vis, x, u);
  // transpose dfs
  fill(vis, false);
  while (!vs.empty()) {
    auto u = vs.back(); vs.pop_back();
    if (vis[u]) continue;
    a.push_back(vector<K>());
    dfsLoop(a.back(), vis, xt, u);
  }
  return a;
}




// COMPONENTS-IDS
// --------------
// Get component id of each vertex.

template <class G, class K>
auto componentIds(const G& x, const vector2d<K>& cs) {
  auto a = createContainer(x, K()); K i = 0;
  for (const auto& c : cs) {
    for (K u : c)
      a[u] = i;
    i++;
  }
  return a;
}




// BLOCKGRAPH
// ----------
// Each component is represented as a vertex.

template <class H, class G, class K>
void blockgraph(H& a, const G& x, const vector2d<K>& cs) {
  auto c = componentIds(x, cs);
  for (auto u : x.vertexKeys()) {
    a.addVertex(c[u]);
    for (auto v : x.edgeKeys(u))
      if (c[u] != c[v]) a.addEdge(c[u], c[v]);
  }
}

template <class G, class K>
auto blockgraph(const G& x, const vector2d<K>& cs) {
  G a; blockgraph(a, x, cs);
  return a;
}




// COMPONENTS-EQUAL
// ----------------

template <class G, class K>
bool componentsEqual(const G& x, const vector<K>& xc, const G& y, const vector<K>& yc) {
  if (xc != yc) return false;
  for (size_t i=0, I=xc.size(); i<I; i++)
    if (!verticesEqual(x, xc[i], y, yc[i])) return false;
  return true;
}

template <class G, class H, class K>
bool componentsEqual(const G& x, const H& xt, const vector<K>& xc, const G& y, const H& yt, const vector<K>& yc) {
  return componentsEqual(x, xc, y, yc) && componentsEqual(xt, xc, yt, yc);
}




// COMPONENTS-HASH
// ---------------

template <class K>
auto componentsHash(const vector2d<K>& cs) {
  vector<size_t> a;
  for (const auto& c : cs)
    a.push_back(hashValue(c));
  return a;
}
