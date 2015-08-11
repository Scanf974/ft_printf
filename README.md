# ft_printf

Like printf in C:      
<cite>int ft_printf(const char *format, ...);</cite>

<h2>Format:</h2>
%[flags][width][.precision][length]specifier

<h2>Flags:</h2>
<table>
  <tr>
    <td>-</td>
    <td>Left-justify within the given field width; Right justification is the default (see width sub-specifier).</td>
  </tr>
  <tr>
    <td>+</td>
    <td>Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.</td>
  </tr>
  <tr>
    <td>(space)</td>
    <td>If no sign is going to be written, a blank space is inserted before the value.</td>
  </tr>
  <tr>
    <td>#</td>
    <td>Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.</td>
  </tr>
  <tr>
    <td>0</td>
    <td>Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).</td>
  </tr>
</table>
