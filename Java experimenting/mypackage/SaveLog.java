/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package mypackage;

public class SaveLog {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected SaveLog(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SaveLog obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        testJNI.delete_SaveLog(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public SaveLog() {
    this(testJNI.new_SaveLog__SWIG_0(), true);
  }

  public SaveLog(String savDir) {
    this(testJNI.new_SaveLog__SWIG_1(savDir), true);
  }

  public void printSaveHistory() {
    testJNI.SaveLog_printSaveHistory(swigCPtr, this);
  }

  public void addSave(Save A) {
    testJNI.SaveLog_addSave(swigCPtr, this, Save.getCPtr(A), A);
  }

  public String loadSave(int savNum) {
    return testJNI.SaveLog_loadSave(swigCPtr, this, savNum);
  }

  public void setDir(String savDir) {
    testJNI.SaveLog_setDir(swigCPtr, this, savDir);
  }

}
