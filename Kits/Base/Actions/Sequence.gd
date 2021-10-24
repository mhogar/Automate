extends Node
class_name Sequence

signal completed

var curr_action : int


func start():
	curr_action = -1
	start_next()


func start_next() -> bool:
	curr_action += 1
	if curr_action >= get_child_count():
		return false
	
	var action : Node = get_children()[curr_action]
	
	# bind completed signal and run
	action.connect("completed", self, "_on_completed")
	action.start()
	
	return true


func _on_completed():
	if !start_next():
		emit_signal("completed")
		
