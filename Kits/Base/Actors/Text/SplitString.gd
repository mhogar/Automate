extends Actor
class_name SplitStringActor

export var deliminator : String = " "

onready var container : HBoxContainer = get_node(".")
onready var actor : TextActor = get_child(0)


func _ready():
	var strings : PoolStringArray = actor.text.split(deliminator)
	for i in strings.size()-1:
		add_new_text_child(actor.duplicate(), strings[i+1])

	update_text(actor, strings[0])


func update_text(actor : TextActor, text : String):
	actor.text = text
	actor.rect_min_size = actor.get_font("font").get_string_size(text) + Vector2.ONE


func add_new_text_child(actor : TextActor, text : String):
	update_text(actor, text)
	add_child(actor)
