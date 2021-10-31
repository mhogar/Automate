extends Action
class_name DelayAction

export var duration : float = 1.0

onready var timer : Timer = $Timer


func _ready():
	timer.wait_time = duration


func start():
	timer.start()
	

func _on_Timer_timeout():
	emit_signal("completed")
