type
  tree=^node;
  node=record
         data:char;
         left,right:tree;
       end;
var
  preo,mido:string;
  root:tree;

procedure print_LRD(root:tree);
  begin
    if root=nil then exit;
    with root^ do
    begin
      print_LRD(left);
      print_LRD(right);
      write(data);
    end;
  end;

function makeTree(preo,mido:string):tree;
  var p,len:longint;
  begin
    if preo='' then exit(nil);
    len:=length(preo);
    p:=pos(preo[1], mido);
    new(makeTree);
    with makeTree^ do
    begin
      data:=preo[1];
      left:=makeTree(copy(preo,2,p-1),copy(mido,1,p-1));
      right:=makeTree(copy(preo,p+1,len-p),copy(mido,p+1,len-p));
    end;
  end;

begin
  readln(preo);
  readln(mido);
  root:=makeTree(preo,mido);
  print_LRD(root);
  writeln;
end.