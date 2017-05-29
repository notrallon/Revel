-- gameObject = rvl.GameObject();
-- gameObject = {};

 
function Start()
	script = gameObject:GetScript();
	sprite = gameObject:GetSprite();

	sprite.width = 5.0;

end

function Update()
	sprite.width = sprite.width + 0.1;
	sprite.height = sprite.height + 0.05;
end
