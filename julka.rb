# encoding: utf-8
#!/usr/bin/env ruby

input = STDIN.read.split.map &:to_i
10.times do |i|
  a, b = input[2*i], input[2*i+1]
  y = (a+b)/2
  x = y-b
  puts y
  puts x
end
