###
#
#  Sort integer arguments (ascending) 
#
###

result = []
ARGV.each do |arg|
  next unless arg =~ /^-?[0-9]+$/

  i_arg = arg.to_i
  
  is_inserted = false
  i = 0
  while i < result.size
    if result[i] > i_arg
      result.insert(i, i_arg)
      is_inserted = true
      break
    end
    i += 1
  end
  result << i_arg unless is_inserted
end

puts result
