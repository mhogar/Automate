extends TweenAction

export var displacement : Vector2 = Vector2(0, 1)


func _ready():
	var start_pos := actor.position
	tween.interpolate_property(
		actor, "position", start_pos-displacement, start_pos, duration, Tween.TRANS_LINEAR, Tween.EASE_OUT
	)
	
	tween.interpolate_property(
		actor, "modulate:a", 0.0, 1.0, duration, Tween.TRANS_LINEAR, Tween.EASE_OUT
	)

