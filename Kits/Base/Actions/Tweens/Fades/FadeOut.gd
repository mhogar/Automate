extends TweenAction
class_name FadeOutAction

export var displacement : Vector2 = Vector2(0, 0)


func init_tweens():
	var start_pos : Vector2 = actor.rect_position
	tween.interpolate_property(
		actor, "rect_position", start_pos, start_pos+displacement, duration, transition_type, Tween.EASE_IN
	)
	
	tween.interpolate_property(
		actor, "modulate:a", 1.0, 0.0, duration, Tween.TRANS_LINEAR, Tween.EASE_IN
	)

