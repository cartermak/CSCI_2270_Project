/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package mypackage;

public class ReplacementPVector extends java.util.AbstractList<Replacement> implements java.util.RandomAccess {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected ReplacementPVector(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(ReplacementPVector obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        testJNI.delete_ReplacementPVector(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public ReplacementPVector(Replacement[] initialElements) {
    this();
    reserve(initialElements.length);

    for (Replacement element : initialElements) {
      add(element);
    }
  }

  public ReplacementPVector(Iterable<Replacement> initialElements) {
    this();
    for (Replacement element : initialElements) {
      add(element);
    }
  }

  public Replacement get(int index) {
    return doGet(index);
  }

  public Replacement set(int index, Replacement e) {
    return doSet(index, e);
  }

  public boolean add(Replacement e) {
    modCount++;
    doAdd(e);
    return true;
  }

  public void add(int index, Replacement e) {
    modCount++;
    doAdd(index, e);
  }

  public Replacement remove(int index) {
    modCount++;
    return doRemove(index);
  }

  protected void removeRange(int fromIndex, int toIndex) {
    modCount++;
    doRemoveRange(fromIndex, toIndex);
  }

  public int size() {
    return doSize();
  }

  public ReplacementPVector() {
    this(testJNI.new_ReplacementPVector__SWIG_0(), true);
  }

  public ReplacementPVector(ReplacementPVector other) {
    this(testJNI.new_ReplacementPVector__SWIG_1(ReplacementPVector.getCPtr(other), other), true);
  }

  public long capacity() {
    return testJNI.ReplacementPVector_capacity(swigCPtr, this);
  }

  public void reserve(long n) {
    testJNI.ReplacementPVector_reserve(swigCPtr, this, n);
  }

  public boolean isEmpty() {
    return testJNI.ReplacementPVector_isEmpty(swigCPtr, this);
  }

  public void clear() {
    testJNI.ReplacementPVector_clear(swigCPtr, this);
  }

  public ReplacementPVector(int count, Replacement value) {
    this(testJNI.new_ReplacementPVector__SWIG_2(count, Replacement.getCPtr(value), value), true);
  }

  private int doSize() {
    return testJNI.ReplacementPVector_doSize(swigCPtr, this);
  }

  private void doAdd(Replacement x) {
    testJNI.ReplacementPVector_doAdd__SWIG_0(swigCPtr, this, Replacement.getCPtr(x), x);
  }

  private void doAdd(int index, Replacement x) {
    testJNI.ReplacementPVector_doAdd__SWIG_1(swigCPtr, this, index, Replacement.getCPtr(x), x);
  }

  private Replacement doRemove(int index) {
    long cPtr = testJNI.ReplacementPVector_doRemove(swigCPtr, this, index);
    return (cPtr == 0) ? null : new Replacement(cPtr, false);
  }

  private Replacement doGet(int index) {
    long cPtr = testJNI.ReplacementPVector_doGet(swigCPtr, this, index);
    return (cPtr == 0) ? null : new Replacement(cPtr, false);
  }

  private Replacement doSet(int index, Replacement val) {
    long cPtr = testJNI.ReplacementPVector_doSet(swigCPtr, this, index, Replacement.getCPtr(val), val);
    return (cPtr == 0) ? null : new Replacement(cPtr, false);
  }

  private void doRemoveRange(int fromIndex, int toIndex) {
    testJNI.ReplacementPVector_doRemoveRange(swigCPtr, this, fromIndex, toIndex);
  }

}
