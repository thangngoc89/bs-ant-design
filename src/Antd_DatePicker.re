open Antd_Helpers;

[%bs.raw {|require("antd/lib/date-picker/style")|}];

[@bs.module]
external reactClass : ReasonReact.reactClass = "antd/lib/date-picker";

[@bs.deriving jsConverter]
type pickerSize = [ | `small | `default | `large];

type moment = MomentRe.Moment.t;

type boolOrProps(_) =
  | ShowTimeBool(bool): boolOrProps(Js.boolean)
  | ShowTimeProps(Antd_TimePicker.TimePickerProps.t('a)): boolOrProps(Antd_TimePicker.TimePickerProps.t('a));

let boolOrPropsToProp = (type a, boolOrProps: boolOrProps(a)) : a =>
  switch boolOrProps {
  | ShowTimeBool(bool) => from_bool(bool)
  | ShowTimeProps(timePickerProps) => timePickerProps
  };

module DatePickerProps = {
  type t('a) = Js.t({. datePickerProps: int} as 'a);
  [@bs.obj]
  external make :
    (
      /*export interface DatePickerProps extends PickerProps, SinglePickerProps*/
      ~showTime: 'a=?, /* TimePickerProps | boolean; */
      ~showToday: Js.boolean=?,
      ~_open: Js.boolean=?,
      ~disabledTime: moment => 'b=?, /* todo: (current: moment.Moment) => { disabledHours?: () => number[],disabledMinutes?: () => number[], disabledSeconds?: () => number[],}; */
      ~onOpenChange: Js.boolean => unit=?,
      ~onOk: moment => unit=?,
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
      ~renderExtraFooter: unit => ReasonReact.reactElement=?,
      ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
      ~disabledDate: moment => bool=?,
      ~dateRender: (moment, moment) => ReasonReact.reactElement=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t(_) =
    "";
};

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
      DatePickerProps.make(
        ~showTime=?Js.Option.map([@bs] (b => boolOrPropsToProp(b)), showTime),
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

module RangePicker = {
  [@bs.module "antd/lib/date-picker"]
  external reactClass : ReasonReact.reactClass = "RangePicker";
  module RangePickerProps = {
    type t('a) = Js.t({. rangePickerProps: int} as 'a);
    [@bs.obj]
    external make :
      (
        /*export interface RangePickerProps extends PickerProps*/
        ~value: 'a=?,
        ~defaultValue: 'b=?,
        ~defaultPickerValue: 'c=?,
        ~onChange: ('d, (string, string)) => unit=?,
        ~onCalendarChange: ('e, (string, string)) => unit=?,
        ~onOk: moment => unit=?,
        ~showTime: 'f=?, /* TimePickerProps | boolean; */
        ~ranges: 'g=?, /* todo: {[range: string]: RangePickerPresetRange,}; */
        ~placeholder: (string, string)=?,
        ~mode: array(string)=?, /* todo: how do i do ? string | string[]; */
        ~disabledTime: (moment, string) => 'h=?, /* todo: (current: moment.Moment, type: string) => { disabledHours?: () => number[],disabledMinutes?: () => number[], disabledSeconds?: () => number[],}; */
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
        ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
        ~_open: Js.boolean=?,
        ~disabledDate: moment => bool=?,
        ~renderExtraFooter: unit => ReasonReact.reactElement=?,
        ~dateRender: (moment, moment) => ReasonReact.reactElement=?,
        ~id: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        unit
      ) =>
      t(_) =
      "";
  };
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
        RangePickerProps.make(
          ~onChange?,
          ~onCalendarChange?,
          ~ranges?,
          ~mode?,
          ~showTime=?Js.Option.map([@bs] (b => boolOrPropsToProp(b)),showTime),
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

module MonthPicker = {
  [@bs.module "antd/lib/date-picker"]
  external reactClass : ReasonReact.reactClass = "MonthPicker";
  module MonthPickerProps = {
    type t('a) = Js.t({. monthPickerProps: int} as 'a);
    [@bs.obj]
    external make :
      (
        /*export interface MonthPickerProps extends PickerProps, SinglePickerProps*/
        ~_open: Js.boolean=?,
        ~onOpenChange: Js.boolean => unit=?,
        ~placeholder: string=?,
        ~monthCellContentRender: (moment, 'a) => ReasonReact.reactElement=?, /* not in interface.tsx */
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
        ~renderExtraFooter: unit => ReasonReact.reactElement=?,
        ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
        ~disabledDate: moment => bool=?,
        ~dateRender: (moment, moment) => ReasonReact.reactElement=?,
        ~id: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        unit
      ) =>
      t(_) =
      "";
  };
  let make =
      (
        ~_open=?,
        ~onOpenChange=?,
        ~placeholder=?,
        ~monthCellContentRender=?,
        ~value=?,
        ~defaultValue=?,
        ~defaultPickerValue=?,
        ~onChange=?,
        ~prefixCls=?,
        ~inputPrefixCls=?,
        ~format=?,
        ~disabled=?,
        ~allowClear=?,
        ~popupStyle=?,
        ~locale=?,
        ~size=?,
        ~getCalendarContainer=?,
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
        MonthPickerProps.make(
          ~onChange?,
          ~onOpenChange?,
          ~_open=?Js.Option.map([@bs] (b => from_bool(b)), _open),
          ~placeholder?,
          ~monthCellContentRender?,
          ~value?,
          ~defaultValue?,
          ~defaultPickerValue?,
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

module WeekPicker = {
  [@bs.module "antd/lib/date-picker"]
  external reactClass : ReasonReact.reactClass = "WeekPicker";
  module WeekPickerProps = {
    type t('a) = Js.t({. weekPickerProps: int} as 'a);
    [@bs.obj]
    /*export interface WeekPickerProps extends PickerProps, SinglePickerProps*/
    external make :
      (
        ~_open: Js.boolean=?,
        ~onOpenChange: Js.boolean => unit=?,
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
        ~renderExtraFooter: unit => ReasonReact.reactElement=?,
        ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
        ~disabledDate: moment => bool=?,
        ~dateRender: (moment, moment) => ReasonReact.reactElement=?,
        ~id: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        unit
      ) =>
      t(_) =
      "";
  };
  let make =
      (
        ~_open=?,
        ~onOpenChange=?,
        ~placeholder=?,
        ~value=?,
        ~defaultValue=?,
        ~defaultPickerValue=?,
        ~onChange=?,
        ~prefixCls=?,
        ~inputPrefixCls=?,
        ~format=?,
        ~disabled=?,
        ~allowClear=?,
        ~popupStyle=?,
        ~locale=?,
        ~size=?,
        ~getCalendarContainer=?,
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
        WeekPickerProps.make(
          ~onChange?,
          ~onOpenChange?,
          ~_open=?Js.Option.map([@bs] (b => from_bool(b)), _open),
          ~placeholder?,
          ~value?,
          ~defaultValue?,
          ~defaultPickerValue?,
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