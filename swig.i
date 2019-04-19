%module test
%include std_string.i
%include std_vector.i
%{
    #include "project.hpp"
%}
typedef long time_t;
%include"project.hpp"
