var
  z, m, n: longint;
begin
  readln(z);
  repeat
    readln(m, n);
    writeln((m-1)+m*(n-1));
    dec(z);
  until
    z=0;
readln;
end.
