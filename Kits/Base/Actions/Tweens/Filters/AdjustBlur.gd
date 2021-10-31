extends TweenAction
class_name AdjustBlurAction

export(float, 0.0, 10.0) var target_blur : float = 5.0


func init_tweens():
	var start_val : float = actor.blur_amount
	tween.interpolate_method(
		actor, "set_blur", start_val, target_blur, duration, transition_type
	)

