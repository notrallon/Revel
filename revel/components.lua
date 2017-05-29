sprite = gameObject:GetSprite();

spriteWidth = sprite.width;

keyboard = rvl.Keyboard();

function Start()
	script = gameObject:GetScript();
	collider = gameObject:AddBoxCollider();
	collider.isStatic = false;
end

function Test()
	sprite.width = sprite.width + 0.1;
	sprite.height = sprite.width;
end

function Update()
	if rvl.Keyboard:IsKeyPressed() then
		collider:Move(-20.0, 0.0)
	end
end
