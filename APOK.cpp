var
   n, z, i, x, p, hp, maxh: longint;
   com: char;
   a, h: array[0..1000000] of longint;
begin
  readln(n, z);
  repeat
    read(com);
    if com='S' then
    begin
      readln(i, x);
      a[i]:=x;
      if hp>h[i] then
        h[i]:=hp+1
      else
        inc(h[i]);
      if h[i]>maxh then
        maxh:=h[i];
    end
    else if com='I' then
    begin
      readln(x);
      p:=x;
      hp:=maxh+1;
    end
    else
    begin
      readln(i);
      if hp>h[i] then
        writeln(p)
      else
        writeln(a[i]);
    end;
    
    dec(z);
  until
    z=0;
readln;
end.
