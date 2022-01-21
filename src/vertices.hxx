#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include "_main.hxx"

using std::vector;
using std::transform;
using std::back_inserter;
using std::equal;




// VERTICES
// --------

template <class G, class F, class D>
auto vertices(const G& x, F fm, D fp) {
  using K = typename G::key_type; vector<K> a;
  copyAppend(x.vertexKeys(), a);
  auto ie = a.end(), ib = a.begin();
  fp(ib, ie); transform(ib, ie, ib, fm);
  return a;
}

template <class G, class F>
auto vertices(const G& x, F fm) {
  return vertices(x, fm, [](auto ib, auto ie) {});
}

template <class G>
auto vertices(const G& x) {
  return vertices(x, [](auto u) { return u; });
}




// VERTEX-DATA
// -----------

template <class G, class J, class F, class D>
auto vertexData(const G& x, const J& ks, F fm, D fp) {
  using K = typename G::key_type;
  using V = decltype(fm(0));
  vector<V> a; vector<K> b;
  copyAppend(ks, b);
  auto ie = b.end(), ib = b.begin();
  fp(ib, ie); transform(ib, ie, back_inserter(a), fm);
  return a;
}

template <class G, class J, class F>
auto vertexData(const G& x, const J& ks, F fm) {
  return vertexData(x, ks, fm, [](auto ib, auto ie) {});
}

template <class G, class J>
auto vertexData(const G& x, const J& ks) {
  return vertexData(x, ks, [&](auto u) { return x.vertexData(u); });
}

template <class G>
auto vertexData(const G& x) {
  return vertexData(x, x.vertexKeys());
}




// CONTAINER
// ---------

template <class G, class T>
auto createContainer(const G& x, const T& _) {
  return vector<T>(x.span());
}

template <class G, class T>
auto createCompressedContainer(const G& x, const T& _) {
  return vector<T>(x.order());
}


template <class G, class T, class J>
void decompressContainer(vector<T>& a, const G& x, const vector<T>& vs, const J& ks) {
  scatter(a, vs, ks);
}

template <class G, class T>
void decompressContainer(vector<T>& a, const G& x, const vector<T>& vs) {
  decompressContainer(a, x, vs, x.vertexKeys());
}

template <class G, class T, class J>
auto decompressContainer(const G& x, const vector<T>& vs, const J& ks) {
  auto a = createContainer(x, T());
  decompressContainer(a, x, vs, ks);
  return a;
}

template <class G, class T>
auto decompressContainer(const G& x, const vector<T>& vs) {
  return decompressContainer(x, vs, x.vertexKeys());
}


template <class G, class T, class J>
void compressContainer(vector<T>& a, const G& x, const vector<T>& vs, const J& ks) {
  gather(a, vs, ks);
}

template <class G, class T>
void compressContainer(vector<T>& a, const G& x, const vector<T>& vs) {
  return compressContainer(a, x, vs, x.vertexKeys());
}

template <class G, class T, class J>
auto compressContainer(const G& x, const vector<T>& vs, const J& ks) {
  auto a = createCompressedContainer(x, T());
  compressContainer(a, x, vs, ks);
  return a;
}

template <class G, class T>
auto compressContainer(const G& x, const vector<T>& vs) {
  return compressContainer(x, vs, x.vertexKeys());
}




// VERTICES-EQUAL
// --------------

template <class G, class K>
bool verticesEqual(const G& x, K u, const G& y, K v) {
  if (x.degree(u) != y.degree(v)) return false;
  auto xe = x.edgeKeys(u), ye = y.edgeKeys(v);
  return equal(xe.begin(), xe.end(), ye.begin());
}

template <class G, class H, class K>
bool verticesEqual(const G& x, const H& xt, K u, const G& y, const H& yt, K v) {
  return verticesEqual(x, u, y, u) && verticesEqual(xt, u, yt, u);
}
