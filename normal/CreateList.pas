program createList;
type range=record min,max:longint end;

function recognize(s:string):range;
  var p:longint;
  begin
    p:=pos(s,'-');
    with recognize do
      if p=0 then
      begin
        val(s,min);
        max:=min;
      end
      else
      begin
        val(copy(s,1,p-1),min);
        val(copy(s,p+1,length(s)-p),max);
      end;
      