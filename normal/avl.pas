program avl;
uses math;
type
  pointer=^node;
  node=record
         left,right:pointer;
         data,height:longint;
       end;
var
  root:pointer;

procedure DLRprint(root:pointer);
  begin
    write(root^.data:4);
    if root^.left<>nil then DLRprint(root^.left);
    if root^.right<>nil then DLRprint(root^.right);
  end;

procedure LDRprint(root:pointer);
  begin
    if root^.left<>nil then LDRprint(root^.left);
    write(root^.data:4);
    if root^.right<>nil then LDRprint(root^.right);
  end;

procedure create(var root:pointer;x:longint);
  begin
    new(root);
    with root^ do
    begin
      left:=nil;right:=nil;
      data:=x;height:=1;
    end;
  end;

function isBalance(root:pointer):boolean;
  begin
    with root^ do
    begin
      if left=right then exit(true);
      if left=nil then exit(right^.height<2);
      if right=nil then exit(left^.height<2);
      exit(abs(left^.height-right^.height)<2);
    end;
  end;

procedure renew(root:pointer);
  begin
    with root^ do
      if left=right then height:=1
      else if right=nil then height:=left^.height+1
      else if left=nil then height:=right^.height+1
      else height:=max(left^.height,right^.height)+1;
  end;

procedure leftRotate(var root:pointer);
  var newRoot:pointer;
  begin
    newRoot:=root^.right;
    root^.right:=newRoot^.left;
    newRoot^.left:=root;
    renew(root); renew(newRoot);
    root:=newRoot;
  end;

procedure rightRotate(var root:pointer);
  var newRoot:pointer;
  begin
    newRoot:=root^.left;
    root^.left:=newRoot^.right;
    newRoot^.right:=root;
    renew(root); renew(newRoot);
    root:=newRoot;
  end;

procedure leftRightRotate(var root:pointer);
  begin
    leftRotate(root^.left);
    rightRotate(root);
  end;

procedure rightLeftRotate(var root:pointer);
  begin
    rightRotate(root^.right);
    leftRotate(root);
  end;

procedure addNode(var root:pointer;x:longint);
  begin
    if root=nil then
    begin create(root,x); exit end;
    if x=root^.data then exit;
    if x<root^.data then
      addNode(root^.left,x)
    else
      addNode(root^.right,x);
    renew(root);
    if isBalance(root) then exit;
    if x<root^.data then
      if x<root^.left^.data then
        rightRotate(root)
      else
        leftRightRotate(root)
    else
      if x>root^.right^.data then
        leftRotate(root)
      else
        rightLeftRotate(root);
  end;

procedure findNode(var root:pointer;x:longint;var find:^pointer);
  begin
    if (root=nil)or(x=root^.data) then
      begin find:=@root;exit end;
    if x<root^.data then
      findNode(root^.left,x,find)
    else
      findNode(root^.right,x,find);
  end;

function deleteMin(var root:pointer;var find:longint):boolean;
  begin
    deleteMin:=false;
    if root^.left=nil then
    begin
      find:=root^.data;
      exit(true);
    end
    else if deleteMin(root^.left,find) then
      if root^.left^.right<>nil then
      begin
        leftRotate(root^.left);
        dispose(root^.left^.left);
        root^.left^.left:=nil;
      end
      else
      begin
        dispose(root^.left);
        root^.left:=nil;
      end;
    renew(root);
  end;

procedure delete(var root:pointer);
  var temp:pointer;
  begin
    with root^ do
      if (left=nil)or(right=nil) then
      begin
        if left=nil then temp:=right else temp:=left;
        dispose(root);root:=temp;
      end
      else
        deleteMin(right,root^.data);
  end;

procedure test;
  const n=10;
  var
    i:longint;
    a:array[1..n] of longint;
    cmd:string;
    bsl:pointer;
    temp:^pointer;
    aim:longint;
  begin
    randomize;bsl:=nil;
    for i:=1 to n do a[i]:=random(150);
    for i:=1 to n do addNode(bsl,i);
    readln(cmd);
    while cmd<>'exit' do
    begin
      case cmd of
        'insert':begin readln(aim);addNode(bsl,aim) end;
        'search':begin readln(aim);findNode(bsl,aim,temp);writeln(temp^<>nil) end;
        'delete':begin readln(aim);findNode(bsl,aim,temp);delete(temp^) end;
        'print':begin DLRprint(bsl);writeln;LDRprint(bsl);writeln end;
      else writeln('That''s not a right command.');
      end;
      readln(cmd);
    end;
  end;

begin
  test;
end.