program dx;

procedure work;
  var
    t:char;
  begin
    read(t);
    if ord(t)=13 then exit;
    work;
    write(t);
  end;

begin
  work;
end.