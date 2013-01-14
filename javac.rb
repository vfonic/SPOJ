# encoding: utf-8
#!/usr/bin/env ruby

STDIN.read.split("\n").each do |identifier|
  if identifier[/(.*[A-Z].*[_].*)|(.*[_].*[A-Z].*)|(.*__.*)|(_$)|(^[A-Z])|(^_)/]
    puts "Error!"
    next
  end
  cpp = identifier.gsub(/(_([a-z]))/) { $1[1,1].upcase }
  if cpp != nil && cpp != identifier
    puts cpp
  else
    puts identifier.gsub(/([A-Z])/) { "_" + $1[0].downcase }
  end
end
