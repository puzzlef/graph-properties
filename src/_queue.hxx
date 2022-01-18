#pragma once
#include <iterator>

using std::iterator_traits;




// BOUNDED-DEQUE-VIEW
// ------------------
// Bounded (circular) deque view capable of storing N elements.
// Can be much more featured!

template <class I>
class BoundedDequeView {
  // Data.
  protected:
  const I xb, xe;
  I ib, ie;
  size_t n;


  // Types.
  public:
  using value_type = typename iterator_traits<I>::value_type;
  protected:
  using T = typename value_type;


  // Read operations.
  public:
  inline size_t size()  const { return n; }
  inline bool   empty() const { return n == 0; }


  // Write operations.
  public:
  inline void push_back(const T& v) {
    ++n; *(ie++) = v;
    if (ie == xe) ie = xb;
  }

  inline void push_front(const T& v) {
    if (ib == xb) ib = xe;
    ++n; *(--ib) = v;
  }

  inline T pop_back() {
    if (ie == xb) ie = xe;
    --n; return *(--ie);
  }

  inline T pop_front() {
    --n; T v = *(ib++);
    if (ib == xe) ib = xb;
    return v;
  }


  // Lifetime operations.
  BoundedDequeView(I xb, I xe) :
  xb(xb), xe(xe), ib(xb), ie(xb), n(0) {}
};


template <class I>
inline auto bounded_deque_view(I xb, I xe) {
  return BoundedDequeView<I>(xb, xe);
}
template <class J>
inline auto boundedDequeView(J& x) {
  return bounded_deque_view(x.begin(), x.end());
}




// PBOUNDED-DEQUE-VIEW
// -------------------
// Fixed circular queue view capable of storing N-1 elements.
// Can be much more featured!

template <class I>
class PBoundedDequeView {
  // Data.
  protected:
  const I xb, xe;
  I ib, ie;


  // Types.
  public:
  using value_type = typename iterator_traits<I>::value_type;
  protected:
  using T = typename value_type;


  // Read operations.
  public:
  inline bool empty() const { return ib == ie; }


  // Write operations.
  public:
  inline void push_back(const T& v) {
    *(ie++) = v;
    if (ie == xe) ie = xb;
  }

  inline void push_front(const T& v) {
    if (ib == xb) ib = xe;
    *(--ib) = v;
  }

  inline T pop_back() {
    if (ie == xb) ie = xe;
    return *(--ie);
  }

  inline T pop_front() {
    T v = *(ib++);
    if (ib == xe) ib = xb;
    return v;
  }


  // Lifetime operations.
  PBoundedDequeView(I xb, I xe) :
  xb(xb), xe(xe), ib(xb), ie(xb) {}
};


template <class I>
inline auto pbounded_deque_view(I xb, I xe) {
  return PBoundedDequeView<I>(xb, xe);
}
template <class J>
inline auto pboundedDequeView(J& x) {
  return pbounded_deque_view(x.begin(), x.end());
}