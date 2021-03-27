<!--
Add here global page variables to use throughout your
website.
The website_* must be defined for the RSS to work
-->
@def website_title = "Embedded C/C++"
@def website_descr = "Embedded C/C++ Mini-Course - Kuwait University"
@def website_url   = "https://alsaibie.github.io/embedded_ccpp/"
@def hasplotly = false
@def hasjsx = false
@def prepath = "embedded_ccpp"

@def author = "Ali AlSaibie, PhD"

@def mintoclevel = 2

<!--
Add here files or directories that should be ignored by Franklin, otherwise
these files might be copied and, if markdown, processed by Franklin which
you might not want. Indicate directories by ending the name with a `/`.
-->
@def ignore = ["node_modules/", "franklin", "franklin.pub"]

<!--
Add here global latex commands to use throughout your
pages. It can be math commands but does not need to be.
For instance:
* \newcommand{\phrase}{This is a long phrase to copy.}
-->
\newcommand{\R}{\mathbb R}
\newcommand{\scal}[1]{\langle #1 \rangle}

<!-- display C code with syntax highlight adopted from https://terasakisatoshi.github.io/MathSeminar.jl/programming/clang/ -->
\newcommand{\Ccode}[2]{
```julia:!#1
#hideall
using Markdown

mdC_code = Markdown.htmlesc(raw"""!#2""")
mdC_code = raw"""!#2"""

mdfile = joinpath(dirname(@OUTPUT), "!#1.md")
open(mdfile,"w") do f
    print(f, mdC_code)
end

C_code=raw"""
!#2
"""

exefile = tempname()

#=
This trick is taken from
https://discourse.julialang.org/t/how-to-make-a-c-function-compiled-by-myself-available-to-ccall/7972/26
=#

open(`gcc -Wall -O2 -march=native -xc -o $exefile -`, "w") do f
    print(f, C_code)
end

run(`$exefile`)
```
\input{c}{!#1.md}
}

\newcommand{\CPPcode}[2]{
```julia:!#1
#hideall
using Markdown

mdC_code = Markdown.htmlesc(raw"""!#2""")
mdC_code = raw"""!#2"""

mdfile = joinpath(dirname(@OUTPUT), "!#1.md")
open(mdfile,"w") do f
    print(f, mdC_code)
end

CPP_code=raw"""
!#2
"""

cppfile = joinpath(dirname(@OUTPUT), "!#1.cpp")

open(cppfile,"w") do f
    print(f, CPP_code)
end

exefile = tempname()

run(`g++ $cppfile -Wall -O2 -march=native -o $exefile`)

run(`$exefile`)
```
\input{cpp}{!#1.md}
}


<!-- run C code and display code and its result https://terasakisatoshi.github.io/MathSeminar.jl/programming/clang/ -->
\newcommand{\Cexec}[2]{
\Ccode{!#1}{!#2}
\codeoutput{!#1}
}

\newcommand{\CPPexec}[2]{
\CPPcode{!#1}{!#2}
\codeoutput{!#1}
}