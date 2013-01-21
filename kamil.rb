STDIN.read.split("\n").each do |l| s = 1
l.each_char do |i| if i=='F'||i=='T'||i=='D'||i=='L'
s=s*2 end end
puts s end