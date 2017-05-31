function Start()
	gameObject:AddBoxCollider();
	collider = gameObject:GetBoxCollider();
	collider.isStatic = false;
end

function Update()
	local speed = 250;

	if rvl.Keyboard.IsKeyPressed(rvl.Keyboard.A) or rvl.Keyboard.IsKeyPressed(rvl.Keyboard.Left) then
		collider:Move(-speed, 0.0)
	elseif rvl.Keyboard.IsKeyPressed(rvl.Keyboard.D) or rvl.Keyboard.IsKeyPressed(rvl.Keyboard.Right) then
		collider:Move(speed, 0.0)
	elseif rvl.Keyboard.IsKeyPressed(rvl.Keyboard.W) or rvl.Keyboard.IsKeyPressed(rvl.Keyboard.Up) then
		collider:Move(0.0, -speed)
	elseif rvl.Keyboard.IsKeyPressed(rvl.Keyboard.S) or rvl.Keyboard.IsKeyPressed(rvl.Keyboard.Down) then
		collider:Move(0.0, speed)
	end
end
