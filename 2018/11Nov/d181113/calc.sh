function calc
{
  awk "BEGIN {print $* }";
}

# I have it in my .bashrc as:
# calc { awk "BEGIN {print $* }"; }
# and it works well.
# putting the equation in single quotes avoids a world of hurt.
# example:
#   calc '(22/7)*(1/17)'
