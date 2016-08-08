program train;
const
  maxn=10000;
  ipath='train.in';
  opath='train.out';
var
  n,i,top:longint;
  car,stack:array[1..maxn] of integer;
procedure get;
  begin
    //assign(input,ipath);
    //reset(input);
    readln(n);
    for i:=1 to n do
      read(car[i]);
  //  close(input);
    top:=0;
    car[n+1]:=-1;
  end;

procedure push(a:integer);
  begin
    inc(top);
    stack[top]:=a;
  end;

procedure regroup;
  var x:longint;
  begin
    for i:=1 to n do
      begin
      push(i);
      if i=car[1] then
        break;
      end;
    x:=i;
    i:=1;
    repeat
      if stack[top]=car[i] then
        begin
          dec(top);
          inc(i);
        end
      else
        begin
          inc(x);
          if x<=n then
            push(x);
        end;
    until x=n+1;
    if top=0 then
      i:=1
    else
      i:=0;
  end;
procedure ending;
  begin
  //  assign(output,opath);
  //  rewrite(output);
    if i=1 then
      writeln('Yes!');
    if i=0 then
      writeln('No!');
   // close(output);
  end;

begin
  get;
  regroup;
  ending;
end.


