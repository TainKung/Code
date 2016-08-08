program makeData;
const
  filename='1304.in';
var
  f1:text;
  // =======================================
  k,len:longint;
  s:string;
  std:string;
  i:longint;
begin
  randomize;
  assign(f1,filename); rewrite(f1);

  // =======================================

  k:=random(16)+1;
  writeln(f1,k);
  std:='0123456789ABCDEF';
  len:=random(10)+1;
  s:='';
  for i:=1 to len do
    s:=s+std[random(k)+1];
  writeln(f1,s);

  // =======================================

  close(f1);
  writeln('Succeed!');
end.