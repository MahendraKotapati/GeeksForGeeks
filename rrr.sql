declare
a integer := &a;
begin
if( mod(a,2) = 0  ) then 
   dbms_output.put_line('even');
else dbms_output.put_line('odd');
end if;
end;

