%module test
%{
    #include "project.hpp"
%}
%include std_string.i
%include std_vector.i
namespace std {
   %template(IntVector) vector<int>;
   %template(DoubleVector) vector<double>;
   %template(PartVector) vector<Part>;
   %template(ReplacementVector) vector<Replacement>;
   %template(RequestVector) vector<Request>;
   %template(PartPVector) vector<Part*>;
}

typedef long time_t;
%include"project.hpp"
