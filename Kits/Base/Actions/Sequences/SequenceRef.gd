extends Action
class_name SequenceRef

export(NodePath) var container_path
onready var sequence : Sequence = get_node(container_path).sequence


func start():
	sequence.connect("completed", self, "_on_completed")
	sequence.start()


func _on_completed():
	emit_signal("completed")

