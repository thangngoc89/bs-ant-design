
open Antd_Helpers;

[%bs.raw {|require("antd/lib/date-picker/style")|}];

[@bs.module]
external reactClass : ReasonReact.reactClass = "antd/lib/date-picker";

[@bs.deriving jsConverter]
type pickerSize = [ | `small | `default | `large];

type moment;
type boolOrTimePickerProps(_) =
  | Bool(bool): boolOrTimePickerProps(Js.boolean)
  | TimePickerProps(Antd_TimePicker.timePickerProps('a)): boolOrTimePickerProps(Antd_TimePicker.timePickerProps('a));

let boolOrTimePickerPropsToProp = (type a, boolOrTimePickerProps: boolOrTimePickerProps(a)) : a =>
  switch boolOrTimePickerProps {
  | Bool(bool) => from_bool(bool)
  | TimePickerProps(timePickerProps) => timePickerProps
  };

type datePickerProps('a) = Js.t( {. datePickerProps: int, } as 'a);
[@bs.obj]
external makeDatePickerProps :
  (
    /*export interface DatePickerProps extends PickerProps, SinglePickerProps*/
    ~showTime: 'a=?, /* TimePickerProps | boolean; */
    ~showToday: Js.boolean=?,
    ~_open: Js.boolean=?, 
    ~disabledTime:  (moment) => 'b=?, /* todo: (current: moment.Moment) => { disabledHours?: () => number[],disabledMinutes?: () => number[], disabledSeconds?: () => number[],}; */
    ~onOpenChange: (Js.boolean)=> unit=?,
    ~onOk: (moment) => unit=?,
    ~placeholder: string=?,

    /*export interface SinglePickerProps*/
    ~value: moment=?,
    ~defaultValue: moment=?,
    ~defaultPickerValue: moment=?,
    ~onChange: (moment, string) => unit=?,

    /*export interface PickerProps*/
    ~prefixCls: string=?,
    ~inputPrefixCls: string=?,
    ~format: string=?,
    ~disabled: Js.boolean=?,
    ~allowClear: Js.boolean=?,
    ~popupStyle: ReactDOMRe.Style.t=?,
    ~locale: 'c=?,
    ~size: string=?,
    ~renderExtraFooter: unit => ReasonReact.reactElement =?,
    ~getCalendarContainer: (Dom.element) => Dom.htmlElement =?,
    ~disabledDate: (moment) => bool=?,
    ~dateRender: (moment, moment) => ReasonReact.reactElement =?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  datePickerProps(_) =
  "";

let make =
    (
      ~showTime=?,
      ~showToday=?,
      ~_open=?,
      ~disabledTime=?,
      ~onOpenChange=?,
      ~onOk=?,
      ~placeholder=?,
      ~value=?,
      ~defaultValue=?,
      ~defaultPickerValue=?,
      ~onChange=?,
      ~prefixCls=?,
      ~inputPrefixCls=?,
      ~format=?,
      ~disabled=?,
      ~renderExtraFooter=?,
      ~allowClear=?,
      ~popupStyle=?,
      ~locale=?,
      ~size=?,
      ~getCalendarContainer=?,
      ~disabledDate=?,
      ~dateRender=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
    makeDatePickerProps(
        ~showTime=?Js.Option.map([@bs] (b => boolOrTimePickerPropsToProp(b)), showTime),
        ~showToday=?Js.Option.map([@bs] (b => from_bool(b)), showToday),
        ~_open=?Js.Option.map([@bs] (b => from_bool(b)), _open),
        ~disabledTime?,
        ~onOpenChange?,
        ~onOk?,
        ~placeholder?,
        ~value?,
        ~defaultValue?,
        ~defaultPickerValue?,
        ~onChange?,
        ~prefixCls?,
        ~inputPrefixCls?,
        ~format?,
        ~disabled=?Js.Option.map([@bs] (b => from_bool(b)), disabled),
        ~renderExtraFooter?,
        ~allowClear=?Js.Option.map([@bs] (b => from_bool(b)), allowClear),
        ~popupStyle?,
        ~locale?,
        ~size?,
        ~getCalendarContainer?,
        ~disabledDate?,
        ~dateRender?,
        ~id?,
        ~className?,
        ~style?,
        ()
      ),
    children
  );
  
  module RangePicker {
    [@bs.module "antd/lib/date-picker"]
    external reactClass : ReasonReact.reactClass = "RangePicker";

    type rangePickerProps('a) = Js.t( {. rangePickerProps: int, } as 'a);
    [@bs.obj]
    external makeRangePickerProps :
      (
        /*export interface RangePickerProps extends PickerProps*/
        ~value: 'a=?,
        ~defaultValue: 'b=?,
        ~defaultPickerValue: 'c=?,
        ~onChange: ('d, (string,string)) => unit=?,
        ~onCalendarChange: ('e, (string,string)) => unit=?,    
        ~onOk: (moment) => unit=?,
        ~showTime: 'f=?, /* TimePickerProps | boolean; */
        ~ranges: 'g=?, /* todo: {[range: string]: RangePickerPresetRange,}; */
        ~placeholder: (string,string)=?,
        ~mode: array(string)=?, /* todo: how do i do ? string | string[]; */
        ~disabledTime:  (moment, string) => 'h=?, /* todo: (current: moment.Moment, type: string) => { disabledHours?: () => number[],disabledMinutes?: () => number[], disabledSeconds?: () => number[],}; */
        ~onPanelChange: 'i=?, /* todo: onPanelChange?: (value?: RangePickerValue, mode?: string | string[]) => void;*/

        /*export interface PickerProps*/
        ~prefixCls: string=?,
        ~inputPrefixCls: string=?,
        ~format: string=?,
        ~disabled: Js.boolean=?,
        ~allowClear: Js.boolean=?,
        ~popupStyle: ReactDOMRe.Style.t=?,
        ~locale: 'c=?,
        ~size: string=?,
        ~getCalendarContainer: (Dom.element) => Dom.htmlElement =?,
        ~_open: Js.boolean=?, 
        ~disabledDate: (moment) => bool=?,
        ~renderExtraFooter: unit => ReasonReact.reactElement =?,
        ~dateRender: (moment, moment) => ReasonReact.reactElement =?,

        ~id: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        unit
      ) =>
      rangePickerProps(_) =
      "";

      let make =
        (
          ~value=?,
          ~defaultValue=?,
          ~defaultPickerValue=?,
          ~onChange=?,
          ~onCalendarChange=?,
          ~onOk=?,
          ~showTime=?,
          ~ranges=?,
          ~placeholder=?,
          ~mode=?,
          ~disabledTime=?,
          ~onPanelChange=?,
          ~prefixCls=?,
          ~inputPrefixCls=?,
          ~format=?,
          ~disabled=?,
          ~allowClear=?,
          ~popupStyle=?,
          ~locale=?,
          ~size=?,
          ~getCalendarContainer=?,
          ~_open=?,
          ~disabledDate=?,
          ~renderExtraFooter=?,
          ~dateRender=?,
          ~id=?,
          ~className=?,
          ~style=?,
          children
        ) =>
      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props=
        makeRangePickerProps(
            ~onChange?,
            ~onCalendarChange=?,
            ~ranges?,
            ~mode?,
            ~showTime=?Js.Option.map([@bs] (b => boolOrTimePickerPropsToProp(b)), showTime),
            ~_open=?Js.Option.map([@bs] (b => from_bool(b)), _open),
            ~disabledTime?,
            ~onOk?,
            ~placeholder?,
            ~value?,
            ~defaultValue?,
            ~defaultPickerValue?,
            ~onPanelChange?,
            ~prefixCls?,
            ~inputPrefixCls?,
            ~format?,
            ~disabled=?Js.Option.map([@bs] (b => from_bool(b)), disabled),
            ~renderExtraFooter?,
            ~allowClear=?Js.Option.map([@bs] (b => from_bool(b)), allowClear),
            ~popupStyle?,
            ~locale?,
            ~size?,
            ~getCalendarContainer?,
            ~disabledDate?,
            ~dateRender?,
            ~id?,
            ~className?,
            ~style?,
            ()
          ),
        children
      );
  };
  
  module MonthPicker {
  };
  
  module WeekPicker {
  };
/*
[@bs.obj]
external makeCommonProps :
  (
    ~allowClear: bool=?,
    ~autoFocus: bool=?,
    ~dateRender: (moment, moment) => ReasonReact.reactElement =?,
    ~disabled: bool=?,
    ~disabledDate: (moment) => bool=?,
    ~getCalendarContainer: ('a) => 'b =?, /* todo: (triggerNode: Element) => HTMLElement */
    ~locale: 'c=?,
    ~open_: bool=?, /* todo: what do we do about open_ */
    ~placeholder: 'd, /* todo: string|RangePicker[] */
    ~popupStyle: ReactDOMRe.Style.t=?,
    ~size: string=?,
    ~onOpenChange: (bool)=> unit=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

type pickerProps('a) = Js.t( {. /* whats in here doesn't matter as long as it's unique */ pickerProps: int, } as 'a);
[@bs.obj]
external makePickerProps : 
  (
    ~prefixCls: string=?,
    ~inputPrefixCls: string=?,
    ~format: string=?,
    ~renderExtraFooter: unit => ReasonReact.reactElement =?,
    unit
  ) =>
  pickerProps(_) =
  "";

type singlePickerProps('a) = Js.t( {. singlePickerProps: int, } as 'a);
[@bs.obj]
external makeSinglePickerProps : 
  (
    ~value: moment=?,
    ~defaultValue: moment=?,
    ~defaultPickerValue: moment=?,
    ~onChange: (moment, string) => unit=?,
    unit
  ) =>
  singlePickerProps(_)=
  "";

let make = (~format=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=reactClass,
      ~props=makePickerProps(~format?, ()),
      children
    );

[@bs.obj]
external makeDatePickerProps : 
  (
    ~showTime: 'a=?, /* todo: TimePickerProps | boolean; */
    ~showToday: bool=?,
    ~disabledTime: 'b=?, /* todo: (current: moment.Moment) => { disabledHours?: () => number[],disabledMinutes?: () => number[], disabledSeconds?: () => number[],}; */
    ~onOk: (moment) => unit,
    unit
  ) =>
  _ =
  "";

type rangePickerValue = int;

type stringOrStringArray = int;

[@bs.obj]
external makeRangePickerProps :
  (
    ~ranges: 'a=?, /* todo: {[range: string]: RangePickerPresetRange,}; */
    ~mode: 'b=?, /* string| string[] */
    ~onPanelChange: (rangePickerValue, stringOrStringArray) => unit=?,
    unit
  ) =>
  _ =
  "";

let make = (~name, ~age=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=reactClass,
    ~props=makeSinglePickerProps(~value=4,()),
    children
  );

  */
