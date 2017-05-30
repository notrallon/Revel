keyboard = rvl.Keyboard();

function Start()
	collider = gameObject:AddBoxCollider();
	collider.isStatic = false;
end

function Update()
	KeyW = rvl.Keyboard.IsKeyPressed(keyboard.W)
	KeyA = rvl.Keyboard.IsKeyPressed(keyboard.A)
	KeyS = rvl.Keyboard.IsKeyPressed(keyboard.S)
	KeyD = rvl.Keyboard.IsKeyPressed(keyboard.D)

	local speed = 100;

	if KeyA then
		collider:Move(-speed, 0.0)
	elseif KeyD then
		collider:Move(speed, 0.0)
	elseif KeyW then
		collider:Move(0.0, -speed)
	elseif KeyS then
		collider:Move(0.0, speed)
	end
end
