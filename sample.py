#-*- coding: utf-8 -*-
import os
from flask import Flask, request, jsonify
import json

app = Flask(__name__)

default_buttons = ['파이썬 퀴즈', '웹 퀴즈', '컴퓨터 퀴즈']

quiz_dict = {'python_quiz_buttons' : ['Guido van Rossum', 'Mark Elliot Zuckerberg', 'Geoffrey Everest Hinton', 'Yann LeCun', 'Andrew Ng'],
'web_quiz_buttons': ["HTML", "XML", "XHTML", "MXML", "JSON"],
'computer_quiz_buttons' : ['애니악', "에드삭", "에드박", "유니박","일리악"]}

answer_list = [quiz_dict['python_quiz_buttons'][0], quiz_dict['web_quiz_buttons'][1]]

choice_list = list(quiz_dict.values())[0]
for i in list(quiz_dict.values())[1:]:
    choice_list =  choice_list+ i


@app.route('/keyboard')
def keyboard():
    return jsonify({
        'type' : 'buttons',
        'buttons' : default_buttons
       })



@app.route('/message', methods=["POST"])
def true_or_false():
    dataRecieve = request.get_json()
    user_input = dataRecieve["content"]
    response_data = None
    if user_input == default_buttons[0]:
        response_data = {
        'message' : {
            "text":'다음 인물들 중 파이썬의 개발자는 누구입니까?'
        },
        "keyboard" : {
            "buttons" : quiz_dict['python_quiz_buttons'],
            "type" : "buttons",
          }
        }

    elif user_input == default_buttons[1]:

        response_data = {
          'message' : {
              "text":'다음 보기중 마크업언어가 아닌것은 무엇입니까?'
          },
          "keyboard" : {
              "type" : "buttons",
              "buttons" : quiz_dict['web_quiz_buttons']
          }
        }
    elif user_input == default_buttons[2]:

        response_data = {
        'message' : {
            "text":'다음 보기중 최초의 컴퓨터는 무엇입니까?'
        },
        "keyboard" : {
              "type" : "buttons",
              "buttons" : quiz_dict['computer_quiz_buttons']
             }
        }

    elif user_input in choice_list :
         if user_input in answer_list:
             response_data = {
                 'message' : {
                  "text":'정답입니다. 다른 퀴즈도 풀어보시겠어요?'
                 },
                 "keyboard" : {
                     "type" : "buttons",
                     "buttons" : default_buttons
                    }
                }
    else:
        response_data = {
            'message' : {
                "text":'틀렸습니다. 다른 퀴즈도 풀어보시겠어요?'},
            "keyboard" : {
               "type" : "buttons",
               "buttons" : default_buttons
            }
         }

    return jsonify(response_data)


if __name__=="__main__":
    app.run(host="0.0.0.0", port=5000)