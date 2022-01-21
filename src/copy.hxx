#pragma once




// COPY
// ----

template <class H, class G, class FV, class FE>
void copyTo(H& a, const G& x, FV fv, FE fe) {
  // add vertices
  for (auto u : x.vertexKeys())
    if (fv(u)) a.addVertex(u, x.vertexValue(u));
  // add edges
  for (auto u : x.vertexKeys()) {
    if (fv(u)) for (auto v : x.edgeKeys(u)) {
      if (fv(v) && fe(u, v)) a.addEdge(u, v, x.edgeValue(u, v));
    }
  }
}

template <class H, class G, class FV>
void copyTo(H& a, const G& x, FV fv) {
  copyTo(a, x, fv, [](auto u, auto v) { return true; });
}

template <class H, class G>
void copyTo(H& a, const G& x) {
  copyTo(a, x, [](auto u) { return true; });
}

template <class G, class FV, class FE>
auto copy(const G& x, FV fv, FE fe) {
  G a; copyTo(a, x, fv, fe);
  return a;
}

template <class G, class FV>
auto copy(const G& x, FV fv) {
  G a; copyTo(a, x, fv);
  return a;
}

template <class G>
auto copy(const G& x) {
  G a; copyTo(a, x);
  return a;
}
