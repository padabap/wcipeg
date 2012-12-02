var
   n, t, a, b, m: longint;
   v, h: array[1..1001] of longint;
   points: array[0..1000, 0..1000] of longint;
function max(x, y: longint): longint;
begin
  if x>y then
    max:=x
  else
    max:=y;
end;
begin
  readln(n, t);
  for a:=1 to n do
    readln(v[a], h[a]);
  points[0, 0]:=0;
  for a:=0 to t do
    for b:=0 to n-1 do
    begin
      points[a, b+1]:=max(points[a, b], points[a, b+1]);
      if a+h[b+1] <= t then
        points[a+h[b+1], b+1]:=max(points[a, b]+v[b+1], points[a+h[b+1], b+1]);
    end;
  for a:=1 to t do
    if m < points[a, n] then
      m:=points[a, n];
  writeln(m);
readln;
end.
