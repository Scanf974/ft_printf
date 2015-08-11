# ft_printf

Like printf in C:

int ft_printf(const char *format, ...);

Format:
%[flags][width][.precision][length]specifier

Flags:
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
</table>
