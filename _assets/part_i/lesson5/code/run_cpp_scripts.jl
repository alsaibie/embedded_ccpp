cd(dirname(@__FILE__))
dir = @__DIR__

"""
gen_cpp_plain(s)
Small helper function to run some cpp code and redirect the output (stdout) to a file.
"""
function gen_cpp_plain(s::String)

    cppfile = joinpath(dir, s)
    exefile = joinpath(dir, "bin", "$(splitext(s)[1]).txt")
    outfile = joinpath(dir, "output", "$(splitext(s)[1]).txt")

    run(`g++ $cppfile -Wall -O2 -march=native -o $exefile`)

    open(outfile, "w") do outf
        redirect_stdout(outf) do
            run(`$exefile`)
        end
    end

end

##

# output
gen_cpp_plain("snippet1.cpp")
gen_cpp_plain("snippet2.cpp")

