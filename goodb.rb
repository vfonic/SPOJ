input = STDIN.read.split.map &:to_i
sol = (1..input[0]).inject(:*)
w = (1..input[1]).inject(:*) || 1
r = (1..input[2]).inject(:*) || 1
t = (1..input[3]).inject(:*) || 1
sol /= w * r * t
sol %= 10**9 + 7
puts sol
