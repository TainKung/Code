type
  tree=^node;
  node=record
         data:char;
         left,right:tree;
       end;
var
  levo,mido:string;

procedure print_DLR(root:tree);
  begin
    if root=nil then exit;
    with root^ do
    begin
      write(data);
      print_DLR(left);
      print_DLR(right);
    end;
  end;

function makeTree(mido:string):tree;
  var i,p,len:longint;
  begin
    if mido='' then exit(nil);
    len:=length(mido);
    i:=1;
    while pos(levo[i],mido)=0 do inc(i);
    p:=pos(levo[i], mido);
    new(makeTree);
    with makeTree^ do
    begin
      data:=levo[i];
      left:=makeTree(copy(mido,1,p-1));
      right:=makeTree(copy(mido,p+1,len-p));
    end;
    makeTree^.data:=levo[i];
    makeTree^.left:=makeTree(copy(mido,1,p-1));
    right:=makeTree(copy(mido,p+1,len-p));
  end;

begin
  readln(mido);
  readln(levo);
  print_DLR(makeTree(mido));
  writeln;
end.