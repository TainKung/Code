program LinkedListSort;
type
  pointer = ^node;
  node = record
           data:longint;
           prev, next:pointer;
         end;
var
  n, i, t:longint;
  head, tail, p:pointer;

procedure swap(var a,b:longint);
  var t:longint;
  begin
    t := a;
    a := b;
    b := t;
  end;

procedure addNode(p:pointer; x:longint);
  var t:pointer;
  begin
    new(t);
    t^.prev := p;
    t^.next := p^.next;
    t^.data := x;
    p^.next^.prev := t;
    p^.next := t;
  end;

procedure inc(var p:pointer);
  begin
    if p<>nil then p:=p^.next;
  end;

procedure dec(var p:pointer);
  begin
    if p<>nil then p:=p^.prev;
  end;

procedure qsortNode(l,r:pointer);
  var
    i, j:pointer;
    p:longint;
  begin
    p:=l^.data;
    i:=l;
    j:=r;
    while true do
    begin
      while (i^.data <= p) and (i<>j) do inc(i);
      while (j^.data >= p) and (i<>j) do dec(j);
      if (i<>j) then swap(i^.data, j^.data);
      if (i<>j) or (i^.next=j) then break;
      inc(i); dec(j);
    end;
    inc(i); dec(j);
    if (i <> l) then qsortNode(l, i);
    if (j <> r) then qsortNode(j, r);
  end;

procedure init(var p:pointer);
  begin
    if (p = nil) then new(p);
    p^.prev:=nil;
    p^.next:=nil;
    p^.data:=0;
  end;

begin
  head:=nil;
  init(head);
  tail:=head;
  head^.next:=tail;
  tail^.prev:=head;
  readln(n);
  for i:=1 to n do
  begin
    read(t);
    addNode(head, t);
  end;
  qsortNode(head^.next, tail^.prev);
  p:=head^.next;
  while (p <> tail) do write(p^.data, ' ');
  writeln;
end.
