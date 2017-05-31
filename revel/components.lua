function Start()
	gameObject:AddBoxCollider();
	collider = gameObject:GetBoxCollider();
	collider.isStatic = false;
end

function Update()
	local speed = 250;

	if rvl.Keyboard.IsKeyPressed(rvl.Keyboard.A) then
		collider:Move(-speed, 0.0)
	elseif rvl.Keyboard.IsKeyPressed(rvl.Keyboard.D) then
		collider:Move(speed, 0.0)
	elseif rvl.Keyboard.IsKeyPressed(rvl.Keyboard.W) then
		collider:Move(0.0, -speed)
	elseif rvl.Keyboard.IsKeyPressed(rvl.Keyboard.S) then
		collider:Move(0.0, speed)
	end
end
