puts ARGV.grep(/^-?[0-9]+$/).map(&:to_i).sort
