extends Action
class_name TweenAction

export var duration : float = 1.0
export var inverted : bool = false

export(NodePath) var actor_path
onready var actor : Node2D = get_node(actor_path)

onready var tween : Tween = $Tween


func start():
	tween.start()
	

func _on_Tween_tween_all_completed():
	emit_signal("completed")
