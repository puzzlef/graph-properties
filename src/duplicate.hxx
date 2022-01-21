#pragma once




// DUPLICATE
// ---------

template <class H, class G, class FV, class FE>
void duplicateTo(H& a, const G& x, FV fv, FE fe) {
  x.forEachVertex([&](auto u, auto d) { if (fv(u)) a.addVertex(u, d); });
  x.forEachVertex([&](auto u, auto d) {
    if (fv(u)) x.forEachEdge([&](auto v, auto w) {
      if (fv(v) && fe(u, v)) a.addEdge(u, v, w);
    });
  });
}

template <class H, class G, class FV>
void duplicateTo(H& a, const G& x, FV fv) {
  duplicateTo(a, x, fv, [](auto u, auto v) { return true; });
}

template <class H, class G>
void duplicateTo(H& a, const G& x) {
  duplicateTo(a, x, [](auto u) { return true; });
}

template <class G, class FV, class FE>
auto duplicate(const G& x, FV fv, FE fe) {
  G a; duplicateTo(a, x, fv, fe);
  return a;
}

template <class G, class FV>
auto duplicate(const G& x, FV fv) {
  G a; duplicateTo(a, x, fv);
  return a;
}

template <class G>
auto duplicate(const G& x) {
  G a; duplicateTo(a, x);
  return a;
}