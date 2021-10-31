extends Action
class_name TweenAction

export var duration : float = 1.0
export(NodePath) var actor_path

onready var actor : Actor = get_node(actor_path)
onready var tween : Tween = $Tween


func init_tweens():
	pass
	

func start():
	init_tweens()
	tween.start()
	

func _on_Tween_tween_all_completed():
	emit_signal("completed")
