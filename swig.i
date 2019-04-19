%module test
%include std_string.i
%include std_vector.i
%{
    #include "project.hpp"
%}
%include"project.hpp"
