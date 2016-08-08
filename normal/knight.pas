program knight;
const
  ipath='knight.in';
  opath='knight.out';
  w=20;
var
  m,n:longint;
  a:array[0..w,0..w] of longint;
  c:array[1..2] of longint;
  f:array[0..w,0..w] of boolean;

procedure get;
  begin
    readln(m,n,c[1],c[2]);
    fillchar(f,sizeof(f),true);
    fillchar(a,sizeof(a),0);
  end;

procedure put;
  begin
    writeln(a[m,n]);
  end;

procedure aset(x,y:longint);
  const
    a:array[1..9] of -2..2=(-2,-2,-1,-1,0,1,1,2,2);
    b:array[1..9] of -2..2=(1,-1,2,-2,0,2,-2,1,-1);
  var
    i:longint;
  begin
    for i:=1 to 9 do
      if (x+a[i] in [0..m]) and (y+b[i] in [0..n]) then
        f[x+a[i],y+b[i]]:=false;
  end;

procedure work;
  var
    i,j:longint;
  begin
    a[0,0]:=1;
    for i:=1 to m do
      if f[i,0] then
        a[i,0]:=a[i-1,0];
    for i:=1 to n do
      if f[0,i] then
        a[0,i]:=a[0,i-1];
    for i:=1 to m do
      for j:=1 to n do
        if f[i,j] then
          a[i,j]:=a[i-1,j]+a[i,j-1];
  end;

begin
  get;
  aset(c[1],c[2]);
  work;
  put;
end.
