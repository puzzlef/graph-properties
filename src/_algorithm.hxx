#pragma once
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <functional>

using std::vector;
using std::unordered_map;
using std::iterator_traits;
using std::hash;
using std::for_each;
using std::any_of;
using std::all_of;
using std::find;
using std::find_if;
using std::lower_bound;
using std::count;
using std::count_if;

using std::transform;
using std::set_difference;
using std::back_inserter;
using std::copy;



// FOR-EACH
// --------
// Perform a sale.

template <class J, class F>
void forEach(J& x, F fn) {
  for_each(x.begin(), x.end(), fn);
}
template <class J, class F>
void forEach(const J& x, F fn) {
  for_each(x.begin(), x.end(), fn);
}
template <class J, class F>
void cforEach(const J& x, F fn) {
  for_each(x.begin(), x.end(), fn);
}




// ANY-OF
// ------
// Is anything useful there?

template <class J, class F>
auto anyOf(const J& x, F fn) {
  return any_of(x.begin(), x.end(), fn);
}




// ALL-OF
// ------
// Is everything there?

template <class J, class F>
auto allOf(const J& x, F fn) {
  return all_of(x.begin(), x.end(), fn);
}




// FIND-*
// ------
// Find a business or its address.

template <class I, class T>
auto find_value(I ib, I ie, const T& v) {
  return find(ib, ie, v);
}
template <class J, class T>
auto findValue(const J& x, const T& v) {
  return find_value(x.begin(), x.end(), v);
}


template <class I, class T>
size_t find_index(I ib, I ie, const T& v) {
  return find(ib, ie, v) - ib;
}
template <class J, class T>
size_t find_index(const J& x, const T& v) {
  return find_index(x.begin(), x.end(), v);
}


template <class I, class T>
size_t find_at(I ib, I ie, const T& v) {
  auto it = find(ib, ie, v);
  return it != ie? it - ib : size_t(-1);
}
template <class J, class T>
size_t findAt(const J& x, const T& v) {
  return find_at(x.begin(), x.end(), v);
}


template <class J, class F>
auto findIf(const J& x, F fn) {
  return find_if(x.begin(), x.end(), fn);
}


template <class I, class F>
size_t find_if_index(I ib, I ie, F fn) {
  return find_if(ib, ie, fn) - ib;
}
template <class J, class F>
size_t findIfIndex(const J& x, F fn) {
  return find_if_index(x.begin(), x.end(), fn);
}


template <class I, class F>
size_t find_if_at(I ib, I ie, F fn) {
  auto it = find_if(ib, ie, fn);
  return it != ie? it - ib : size_t(-1);
}
template <class J, class F>
size_t findIfAt(const J& x, F fn) {
  return find_if_at(x.begin(), x.end(), fn);
}




// LOWER-BOUND/FIND
// ----------------
// Find closest business, or its address.

template <class J, class T>
auto lowerBound(const J& x, const T& v) {
  return lower_bound(x.begin(), x.end(), v);
}
template <class J, class T, class FL>
auto lowerBound(const J& x, const T& v, FL fl) {
  return lower_bound(x.begin(), x.end(), v, fl);
}


template <class I, class T>
size_t lower_bound_index(I ib, I ie, const T& v) {
  return lower_bound(ib, ie, v) - ib;
}
template <class I, class T, class FL>
size_t lower_bound_index(I ib, I ie, const T& v, FL fl) {
  return lower_bound(ib, ie, v, fl) - ib;
}
template <class J, class T>
size_t lowerBoundIndex(const J& x, const T& v) {
  return lower_bound_index(x.begin(), x.end(), v);
}
template <class J, class T, class FL>
size_t lowerBoundIndex(const J& x, const T& v, FL fl) {
  return lower_bound_index(x.begin(), x.end(), v, fl);
}


template <class I, class T>
auto lower_find(I ib, I ie, const T& v) {
  auto it = lower_bound(ib, ie, v);
  return it != ie && *it == v? it : ie;
}
template <class I, class T, class FL>
auto lower_find(I ib, I ie, const T& v, FL fl) {
  auto it = lower_bound(ib, ie, v, fl);
  return it != ie && *it == v? it : ie;
}
template <class I, class T, class FL, class FE>
auto lower_find(I ib, I ie, const T& v, FL fl, FE fe) {
  auto it = lower_bound(ib, ie, v, fl);
  return it != ie && fe(*it, v)? it : ie;
}
template <class J, class T>
auto lowerFind(const J& x, const T& v) {
  return lower_find(x.begin(), x.end(), v);
}
template <class J, class T, class FL>
auto lowerFind(const J& x, const T& v, FL fl) {
  return lower_find(x.begin(), x.end(), v, fl);
}
template <class J, class T, class FL, class FE>
auto lowerFind(const J& x, const T& v, FL fl, FE fe) {
  return lower_find(x.begin(), x.end(), v, fl, fe);
}


template <class I, class T>
size_t lower_find_index(I ib, I ie, const T& v) {
  return lower_find(ib, ie, v) - ib;
}
template <class I, class T, class FL>
size_t lower_find_index(I ib, I ie, const T& v, FL fl) {
  return lower_find(ib, ie, v, fl) - ib;
}
template <class I, class T, class FL, class FE>
size_t lower_find_index(I ib, I ie, const T& v, FL fl, FE fe) {
  return lower_find(ib, ie, v, fl, fe) - ib;
}
template <class J, class T>
size_t lowerFindIndex(const J& x, const T& v) {
  return lower_find_index(x.begin(), x.end(), v);
}
template <class J, class T, class FL>
size_t lowerFindIndex(const J& x, const T& v, FL fl) {
  return lower_find_index(x.begin(), x.end(), v, fl);
}
template <class J, class T, class FL, class FE>
size_t lowerFindIndex(const J& x, const T& v, FL fl, FE fe) {
  return lower_find_index(x.begin(), x.end(), v, fl, fe);
}


template <class I, class T>
size_t lower_find_at(I ib, I ie, const T& v) {
  auto it = lower_find(ib, ie, v);
  return it != ie? it - ib : size_t(-1);
}
template <class I, class T, class FL>
size_t lower_find_at(I ib, I ie, const T& v, FL fl) {
  auto it = lower_find(ib, ie, v, fl);
  return it != ie? it - ib : size_t(-1);
}
template <class I, class T, class FL, class FE>
size_t lower_find_at(I ib, I ie, const T& v, FL fl, FE fe) {
  auto it = lower_find(ib, ie, v, fl, fe);
  return it != ie? it - ib : size_t(-1);
}
template <class J, class T>
size_t lowerFindAt(const J& x, const T& v) {
  return lower_find_at(x.begin(), x.end(), v);
}
template <class J, class T, class FL>
size_t lowerFindAt(const J& x, const T& v, FL fl) {
  return lower_find_at(x.begin(), x.end(), v, fl);
}
template <class J, class T, class FL, class FE>
size_t lowerFindAt(const J& x, const T& v, FL fl, FE fe) {
  return lower_find_at(x.begin(), x.end(), v, fl, fe);
}




// COUNT-*
// -------
// Count businesses in a sector.

template <class I, class T>
size_t count_value(I ib, I ie, const T& v) {
  return count(ib, ie, v);
}
template <class J, class T>
size_t countValue(const J& x, const T& v) {
  return count_value(x.begin(), x.end(), v);
}


template <class J, class F>
int countIf(const J& x, F fn) {
  return count_if(x.begin(), x.end(), fn);
}


template <class I, class FM>
auto count_each(I ib, I ie, FM fm) {
  using K = decltype(fm(*ib)); unordered_map<K, size_t> a;
  for_each(ib, ie, [&](const K& v) { ++a[fm(v)]; });
  return a;
}
template <class I>
auto count_each(I ib, I ie) {
  auto fm = [](const auto& v) { return v; };
  return count_each(ib, ie, fm);
}
template <class J, class FM>
auto countEach(const J& x, FM fm) {
  return count_each(x.begin(), x.end(), fm);
}
template <class J>
auto countEach(const J& x) {
  return count_each(x.begin(), x.end());
}





// HASH-VALUE
// ----------

template <class I>
size_t hash_value(I ib, I ie) {
  // From boost::hash_combine.
  using T = typename iterator_traits<I>::value_type; size_t a = 0;
  for (; ib != ie; ++ib)
    a ^= hash<T>{}(*ib) + 0x9e3779b9 + (a<<6) + (a>>2);
  return a;
}
template <class J>
size_t hashValue(const J& x) {
  return hash_value(x.begin(), x.end());
}


template <class I, class T>
size_t hash_unordered(I ib, I ie, vector<T>& buf) {
  copy_write(ib, ie, buf);
  sort(buf.begin(), buf.end());
  return hash_value(buf.begin(), buf.end());
}
template <class I>
size_t hash_unordered(I ib, I ie) {
  using T = typename iterator_traits<I>::value_type; vector<T> buf;
  return hash_unordered(ib, ie, buf);
}
template <class J, class T>
size_t hashUnordered(const J& x, vector<T>& buf) {
  return hash_unordered(x.begin(), x.end(), buf);
}
template <class J>
size_t hashUnordered(const J& x) {
  return hash_unordered(x.begin(), x.end());
}



// INDICES
// -------
// Keep the address of each business (yellow pages).

template <class I, class M>
auto value_indices(I ib, I ie, M& a) {
  size_t i = 0;
  for (; ib != ie; ++ib)
    a[*ib] = i++;
  return a;
}
template <class I>
auto value_indices(I ib, I ie) {
  using K = typename iterator_traits<I>::value_type; unordered_map<K, size_t> a;
  return value_indices(ib, ie, a);
}
template <class J, class M>
auto valueIndices(const J& x, M& a) {
  return value_indices(x.begin(), x.end(), a);
}
template <class J>
auto valueIndices(const J& x) {
  return value_indices(x.begin(), x.end());
}




// COPY-*
// ------

template <class IX, class IA>
auto copy_values(IX xb, IX xe, IA ab) {
  return copy(xb, xe, ab);
}
template <class JX, class JA>
auto copyValues(const JX& x, JA& a) {
  return copy_values(x.begin(), x.end(), x.begin());
}


template <class I, class T>
auto copy_append(I ib, I ie, vector<T>& a) {
  return a.insert(a.end(), ib, ie);
}
template <class J, class T>
auto copyAppend(const J& x, vector<T>& a) {
  return copy_append(x.begin(), x.end(), a);
}


template <class I, class T>
auto copy_write(I ib, I ie, vector<T>& a) {
  a.clear();
  return copy_append(ib, ie, a);
}
template <class J, class T>
auto copyWrite(const J& x, vector<T>& a) {
  return copy_write(x.begin(), x.end(), a);
}


template <class I>
auto copy_vector(I ib, I ie) {
  using T = typename iterator_traits<I>::value_type; vector<T> a;
  copy_append(ib, ie, a);
  return a;
}
template <class J>
auto copy_vector(const J& x) {
  return copy_vector(x.begin(), x.end());
}




// TRANSFORM
// ---------
// Switch around your portfolio.

template <class IX, class IA, class FM>
auto transform_values(IX xb, IX xe, IA ab, FM fm) {
  return transform(xb, xe, ab, fm);
}
template <class JX, class JA, class FM>
auto transformValues(const JX& x, JA& a, FM fm) {
  return transform(x.begin(), x.end(), a.begin(), fm);
}


template <class I, class T, class FM>
auto transform_append(I ib, I ie, vector<T>& a, FM fm) {
  return transform(ib, ie, back_inserter(a), fm);
}
template <class J, class T, class FM>
auto transformAppend(const J& x, vector<T>& a, FM fm) {
  return transform_append(x.begin(), x.end(), a, fm);
}


template <class I, class FM>
auto transform_vector(I ib, I ie, FM fm) {
  using T = typename iterator_traits<I>::value_type; vector<T> a;
  return transform_append(ib, ie, a, fm);
}
template <class J, class FM>
auto transformVector(const J& x, FM fm) {
  return transform_vector(x.begin(), x.end(), fm);
}




// SORT
// ----
// Arrange your portfolio by ROCE.

template <class I>
void sort_values(I ib, I ie) {
  sort(ib, ie);
}
template <class I, class FL>
void sort_values(I ib, I ie, FL fl) {
  sort(ib, ie, fl);
}
template <class J>
void sortValues(J& x) {
  sort(x.begin(), x.end());
}
template <class J, class FL>
void sortValues(J& x, FL fl) {
  sort(x.begin(), x.end(), fl);
}




// SET-DIFFERENCE-*
// ----------------

template <class JX, class JY, class JA>
auto setDifference(const JX& x, const JY& y, JA& a) {
  return set_difference(x.begin(), x.end(), y.begin(), y.end(), a.begin());
}
template <class JX, class JY, class JA, class FE>
auto setDifference(const JX& x, const JY& y, JA& a, FE fe) {
  return set_difference(x.begin(), x.end(), y.begin(), y.end(), a.begin(), fe);
}


template <class IX, class IY, class T>
auto set_difference_append(IX xb, IX xe, IY yb, IY ye, vector<T>& a) {
  return set_difference(xb, xe, yb, ye, back_inserter(a));
}
template <class IX, class IY, class T, class FE>
auto set_difference_append(IX xb, IX xe, IY yb, IY ye, vector<T>& a, FE fe) {
  return set_difference(xb, xe, yb, ye, back_inserter(a), fe);
}
template <class JX, class JY, class T>
auto setDifferenceAppend(const JX& x, const JY& y, vector<T>& a) {
  return set_difference_append(x.begin(), x.end(), y.begin(), y.end(), a);
}
template <class JX, class JY, class T, class FE>
auto setDifferenceAppend(const JX& x, const JY& y, vector<T>& a, FE fe) {
  return set_difference_append(x.begin(), x.end(), y.begin(), y.end(), a, fe);
}


template <class IX, class IY>
auto set_difference_vector(IX xb, IX xe, IY yb, IY ye) {
  using T = typename iterator_traits<IX>::value_type; vector<T> a;
  return set_difference_append(xb, xe, yb, ye, a);
}
template <class IX, class IY, class FE>
auto set_difference_vector(IX xb, IX xe, IY yb, IY ye, FE fe) {
  using T = typename iterator_traits<IX>::value_type; vector<T> a;
  return set_difference_append(xb, xe, yb, ye, a, fe);
}
template <class JX, class JY>
auto setDifferenceVector(const JX& x, const JY& y) {
  return set_difference_vector(x.begin(), x.end(), y.begin(), y.end());
}
template <class JX, class JY, class FE>
auto setDifferenceVector(const JX& x, const JY& y, FE fe) {
  return set_difference_vector(x.begin(), x.end(), y.begin(), y.end(), fe);
}
