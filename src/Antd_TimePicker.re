open Antd_Helpers;

[%bs.raw {|require("antd/lib/time-picker/style")|}];

[@bs.module "antd/lib/time-picker"]
external reactClass : ReasonReact.reactClass = "default";

type moment = MomentRe.Moment.t;

[@bs.deriving jsConverter]
type pickerSize = [ | `small | `default | `large];

type t('a) = Js.t({. timePickerProps: int} as 'a);
[@bs.obj]
external makeProps :
  (
    ~size: string=?,
    ~value: moment=?,
    ~defaultValue: moment=?, /* should be moment | moment[] */
    ~_open: Js.boolean=?,
    ~format: string=?,
    ~onChange: (moment, string) => unit=?,
    ~onOpenChange: Js.boolean => unit=?,
    ~disabled: Js.boolean=?,
    ~placeholder: string=?,
    ~prefixCls: string=?,
    ~hideDisabledOptions: Js.boolean=?,
    ~disabledHours: unit => array(int)=?,
    ~disabledMinutes: int => array(int)=?,
    ~disabledSEconds: (int, int) => array(int)=?,
    ~getPopupContainer: Dom.element => Dom.htmlElement=?,
    ~addon: 'a=?,
    ~use12Hours: Js.boolean=?,
    ~focusOnOpen: Js.boolean=?,
    ~hourStep: int=?,
    ~minuteStep: int=?,
    ~secondStep: int=?,
    ~allowEmpty: Js.boolean=?,
    ~clearText: Js.boolean=?,
    ~defaultOpenValue: moment=?,
    ~popupClassName: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  t(_) =
  "";


let make =
    (
      ~size=?,
      ~value=?,
      ~defaultValue=?,
      ~_open=?,
      ~format=?,
      ~onChange=?,
      ~onOpenChange=?,
      ~disabled=?,
      ~placeholder=?,
      ~prefixCls=?,
      ~hideDisabledOptions=?,
      ~disabledHours=?,
      ~disabledMinutes=?,
      ~disabledSEconds=?,
      ~getPopupContainer=?,
      ~addon=?,
      ~use12Hours=?,
      ~focusOnOpen=?,
      ~hourStep=?,
      ~minuteStep=?,
      ~secondStep=?,
      ~allowEmpty=?,
      ~clearText=?,
      ~defaultOpenValue=?,
      ~popupClassName=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~size=?Js.Option.map([@bs] (b => pickerSizeToJs(b)), size),
        ~value?,
        ~defaultValue?,
        ~_open=?Js.Option.map([@bs] (b => from_bool(b)), _open),
        ~format?,
        ~onChange?,
        ~onOpenChange?,
        ~disabled=?Js.Option.map([@bs] (b => from_bool(b)), disabled),
        ~placeholder?,
        ~prefixCls?,
        ~hideDisabledOptions=?
          Js.Option.map([@bs] (b => from_bool(b)), hideDisabledOptions),
        ~disabledHours?,
        ~disabledMinutes?,
        ~disabledSEconds?,
        ~getPopupContainer?,
        ~addon?,
        ~use12Hours=?Js.Option.map([@bs] (b => from_bool(b)), use12Hours),
        ~focusOnOpen=?Js.Option.map([@bs] (b => from_bool(b)), focusOnOpen),
        ~hourStep?,
        ~minuteStep?,
        ~secondStep?,
        ~allowEmpty=?Js.Option.map([@bs] (b => from_bool(b)), allowEmpty),
        ~clearText=?Js.Option.map([@bs] (b => from_bool(b)), clearText),
        ~defaultOpenValue?,
        ~popupClassName?,
        ~id?,
        ~className?,
        ~style?,
        ()
      ),
    children
  );