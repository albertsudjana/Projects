from scheme_reader import *
src = Buffer(tokenize_lines(["(+ 1 ", "(23 4) ("]))
a = src.remove_front()
b = src.remove_front()
c =src.remove_front()

print(read_tail(Buffer(tokenize_lines(['2 (3 4))'])))
