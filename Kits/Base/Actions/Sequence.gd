extends Node
class_name Sequence

signal completed

var next_action : int
var active_count : int
var is_blocked : bool

func start():
	next_action = 0
	active_count = 0
	is_blocked = false
	
	start_next()


func start_next() -> bool:
	while !is_blocked:
		if next_action >= get_child_count():
			return false
		
		# get next action
		var action : Action = get_children()[next_action]
		next_action += 1
		
		# skip action is enabled
		if !action.is_enabled:
			continue
		
		# bind completed signal and run
		action.connect("completed", self, "_on_completed", [action])
		action.start()
		
		# increment counts
		active_count += 1
		is_blocked = action.is_blocking
	
	return true


func _on_completed(action : Action):
	# decrement counts
	active_count -= 1
	if action.is_blocking:
		is_blocked = false
	
	# start next action(s) and mark as completed if no more
	if !start_next():
		emit_signal("completed")
		
