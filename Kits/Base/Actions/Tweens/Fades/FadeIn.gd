extends TweenAction
class_name FadeInAction

export var displacement : Vector2 = Vector2(0, 0)


func init_tweens():
	var start_pos := actor.position
	tween.interpolate_property(
		actor, "position", start_pos-displacement, start_pos, duration, transition_type, Tween.EASE_OUT
	)
	
	tween.interpolate_property(
		actor, "modulate:a", 0.0, 1.0, duration, Tween.TRANS_LINEAR, Tween.EASE_OUT
	)

