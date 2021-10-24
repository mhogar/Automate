extends TweenAction

export var displacement : Vector2 = Vector2(0, 0)


func _ready():
	var start_pos := actor.position
	tween.interpolate_property(
		actor, "position", start_pos, start_pos+displacement, duration, Tween.TRANS_LINEAR, Tween.EASE_IN
	)
	
	actor.modulate.a = 1.0
	tween.interpolate_property(
		actor, "modulate:a", 1.0, 0.0, duration, Tween.TRANS_LINEAR, Tween.EASE_IN
	)

