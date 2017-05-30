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

	if KeyA then
		collider:Move(-20.0, 0.0)
	elseif KeyD then
		collider:Move(20.0, 0.0)
	elseif KeyW then
		collider:Move(0.0, -20.0)
	elseif KeyS then
		collider:Move(0.0, 20.0)
	end
end
